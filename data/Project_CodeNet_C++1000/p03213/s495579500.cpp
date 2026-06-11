#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

map< int, int > prime_factor(int64_t n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

signed main(){
    int N; cin>>N;

    map<int, int> pm_num;
    for(int i=1;i<N+1;i++){
        pm_num[i] = 0;
    }
    for(int i=1;i<N+1;i++){
        map<int, int> temp = prime_factor(i);
        for(auto iter = temp.begin(); iter!=temp.end(); iter++){
            pm_num[iter->first] += iter->second;
        }
    }
    int tot_count = 0;
    for(int i=1;i<N+1;i++){
    for(int j=1;j<N+1;j++){
        if(i==j)continue;
    for(int k=j+1;k<N+1;k++){
        if(i==k||j==k)continue;
        if(pm_num[i]>=2 && pm_num[j]>=4 && pm_num[k]>=4){
            tot_count++;

        }
    }
    }
    }


    for(int i=1;i<N+1;i++){
        if(pm_num[i]>=74){
            tot_count++;
        }
    }

    for(int i=1;i<N+1;i++){
    for(int j=1;j<N+1;j++){
        if(i==j)continue;
        if(pm_num[i]>=24 && pm_num[j]>=2){
            tot_count++;
        }
    }
    }

    for(int i=1;i<N+1;i++){
    for(int j=1;j<N+1;j++){
        if(i==j)continue;
        if(pm_num[i]>=14 && pm_num[j]>=4){
            tot_count++;
        }
    }
    }




    cout<<tot_count<<endl;

    return 0;
}
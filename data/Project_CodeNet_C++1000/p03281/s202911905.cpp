#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
    int N;
    cin >> N;
    int ans =0;
    for(int i=1;i<N+1;i++){
      int num = 0;
      if(i%2==0){
        continue;
      }
      for(int h=1;h<i+1;h++){
        if(i%h==0){
          num++;
        }
      }
      if(num==8){
        ans++;
      }
    }
    
    printl(ans);
}

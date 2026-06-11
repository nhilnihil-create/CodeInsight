#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}


int main(){
  
  string s;
  cin>>s;
  int n = s.size();
  bool flag = true;
  REP(i,n){
    if(i==0){
      if(s[i]=='0'){
        flag = false;
        break;
      }
    }else if(i==n-1){
      if(s[i]=='1'){
        flag = false;
        break;
      }
    }else{
      if(s[i] != s[n-2-i]){
        flag = false;
        break;
      }
    }
  }
  if(!flag){
    cout<<-1<<endl;
    return 0;
  }
  
  vector<int> nums;
  REP(i,n){
    if(s[i]=='1'){
      nums.push_back(i+1);
    }
  }
  vector<int> G[n];
  int nowv = 0;
  int sub_v;
  int nowc = 1;
  int r = nums.size();
  int temp_num;
  REP(i,r){
    temp_num = nums[i];
    sub_v = nowv + 1;
    while(nowc<temp_num){
      ++nowc;
      G[nowv].push_back(sub_v);
      G[sub_v].push_back(nowv);
      ++sub_v;
    }
    if(sub_v>=n)break;
    G[nowv].push_back(sub_v);
    G[sub_v].push_back(nowv);
    nowv = sub_v;
    nowc++;
  }
  
  REP(i,n){
    for(int j:G[i]){
      if(i<j){
        cout<<i+1<<' '<<j+1<<endl;
      }
    }  
  }
  
  return 0;
}

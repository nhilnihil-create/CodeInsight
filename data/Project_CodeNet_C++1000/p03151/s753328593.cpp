#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}

int main(){
  ll N; cin >> N;
  ll a[N]; REP(i,N){cin >> a[i];}
  ll b[N]; REP(i,N){cin >> b[i];}
  ll d[N]; REP(i,N){d[i] = a[i]-b[i];}
  sort(d,d+N);
  ll left_p = 0;
  ll left = d[0];
  ll right_p = N-1;
  ll right = d[right_p];
  
  ll r = -1;
  bool can = true;
  while(1){
    //printf("%Ld %Ld\n",right,left);
    if(right+left>0){
      if(left>=0){break;}
      right += left;
      left_p++;
      left = d[left_p];
      if(left>=0){break;}
    }else if(right+left==0){
      left_p++;
      left = d[left_p];
      right_p--;
      right = d[right_p];
      if(left>=0){break;}
      else if(right<=0){can = false;break;}
    }else{
      if(right<=0){can = false;break;}
      left += right;
      right_p--;
      right = d[right_p];
      if(right<=0){can = false;break;}
    }
  }
  if(can){
	r = left_p + (left != d[left_p]);
  	r += N-1-right_p + (right != d[right_p]);
  }
  cout << r << "\n";
}
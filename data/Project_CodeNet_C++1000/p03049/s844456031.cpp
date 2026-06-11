#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
#define LINEY "YES\n"
#define Liney "Yes\n"
#define LINEN "NO\n"
#define Linen "No\n"

int func(string s){
  char c,d;
  int count = 0;
  int s_size = s.size();
  for(int i=1;i<s_size;i++){
    c = s[i-1];
    d = s[i];
    if(c=='A' && d=='B'){count++;}
  }
  return count;
}

// -A B-A B- 

int main(){
  int N; cin>>N;
  string s; char t,e;
  int count = 0;
  int num_a = 0;
  int num_b = 0;
  int num_ab = 0;
  REP(i,N){
    cin >> s;
    count += func(s);
    t = s[0];
    e = s[s.size()-1];
    if(e=='A'){
      if(t=='B'){num_ab++;}
      else{num_a++;}
    }
    else if(t=='B'){num_b++;}
  }
  if(num_a+num_b>0){
    count += min(num_a,num_b)+num_ab;
  }else{
    count += max(num_ab-1,0);
  }
  printf("%d\n",count);
}

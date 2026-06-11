#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll> 
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,cnt=0;cin>>n;
  ll seat=0,lseat=0,rseat=n;
  string s,ls,rs;
  print(0);cin>>s;ls=s,rs=s;
  while(cnt<19) {
    seat=(lseat+rseat)/2;
    print(seat);
    cin>>s;
    if(s=="Vacant") break;
    if(((seat-lseat)%2)^(ls==s)) {lseat=seat;ls=s;}
    else {rseat=seat;rs=s;}
    cnt++;
  }
  return 0;
}
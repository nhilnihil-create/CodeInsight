#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
void  solve(){
  int D;
  int G;
  cin >> D >> G;
  vector<int> p(D);
  vector<int> c(D);

  int max_count = 0;

  for(int i=0;i<D;i++){
    cin >> p.at(i) >> c.at(i);
    max_count += p.at(i);
  }

  int answer_count = max_count;

  for(int bit=0;bit<(1<<D);bit++){
    bitset<10> s(bit);
    int sum = 0;
    int count = 0;
    for(int i=D-1;i>=0;--i){
      if((bit>>i)&1){
        for(int j=0;j<p.at(i);++j){
          sum+=100*(i+1);
          count++;
          if(j+1==p.at(i)) sum += c.at(i);
          if((sum>=G)&&(count<=answer_count)){
              answer_count = count;
              break;
          }
        }
      }
    }
  }

  cout << answer_count << endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}

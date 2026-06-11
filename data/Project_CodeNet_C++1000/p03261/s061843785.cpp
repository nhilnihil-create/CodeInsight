#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
   int n; cin >> n;
   string w; cin >> w;
   map<string,int> check;
   check[w]++;
   rep(i,n-1){
       string s; cin >> s;
       if(w[w.length()-1]!=s[0] || check[s]!=0){
           cout << "No" << endl;
           return 0;
       }
       w=s;
       check[s]++;
   }
   cout << "Yes" << endl;
return 0;
}
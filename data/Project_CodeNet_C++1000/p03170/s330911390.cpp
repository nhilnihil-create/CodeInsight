#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
// scanf("%d %d %d %d",&w,&b,&d,&s); %lld
// printf("%d\n" ,points);
// const double PI=acos(-1);

const int MAX=1e5+5;
bool dp[MAX];
int n,k;

int main(){
    cin >> n >> k;
    int aux;
    vector<int> stones;
    for(int i=0;i<n;i++){
        cin >> aux;
        stones.pb(aux);
    }
    for(int i=1;i<=k;i++){
        bool ok=false;
        for(int j=0;j<n;j++){
            if(i-stones[j]>-1){
                if(!dp[i-stones[j]]) ok=true;
            }
        }
        dp[i]=ok;
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}

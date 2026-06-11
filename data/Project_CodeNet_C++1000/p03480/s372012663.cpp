#include <iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout<< "YES"<<endl;
#define No cout<< "No"<<endl;
#define Yes cout<< "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 100000;

int main(){
    
    string s;
    int ans=INF;
    cin >> s;
    
    rep(i,s.size()-1){
        if(s[i]!=s[i+1]){
            ans=min(max(i+1,(int)s.size()-(i+1)),ans);
        }
    }
    if(ans==INF)ans=s.size();
    cout << ans<<endl;
    return 0;
}

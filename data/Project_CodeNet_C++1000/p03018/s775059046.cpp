#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define MAX_V 100001
#define MOD 1000000007
typedef vector<vector<int> > Graph;
int p[1000];

int main(){
    string s;cin>>s;
    int count_a=0;
    int flag=-1;
    int ren=1;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        if(flag>0){
            flag--;
            continue;
        }
        if(s[i]=='A'){
            count_a++;
            continue;
        }
        if(count_a>0&&i+1<s.size()&&s[i]=='B'&&s[i+1]=='C'){
            ans+=count_a;
            flag=1;
        }
        else{
            count_a=0;
        } 
    }
    cout<<ans<<endl;
}
 


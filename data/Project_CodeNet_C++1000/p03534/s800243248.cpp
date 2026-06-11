#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#include<limits>
#include<bitset>
#include<ctype.h>
#include<set>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007LL;
const ll INF=1000000000;
const int MAX=100001;
struct edge{int to,cost;};
typedef pair<int,int> P;
int main(){
    string s;
    cin>>s;
    int sl=s.length();
    int a=0;int b=0;int c=0;
    for(int i=0;i<sl;i++){
        if(s[i]=='a'){
            a++;
        }else if(s[i]=='b'){
            b++;
        }else{
            c++;
        }
    }
    int ma=max(a,max(b,c));
    int mi=min(a,min(b,c));
    if(ma-mi<2){
        if(mi>0){
            cout<<"YES"<<endl;
        }else{
            if(ma==1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }else{
        cout<<"NO"<<endl;
    }
    getchar();
    getchar();
}

                           

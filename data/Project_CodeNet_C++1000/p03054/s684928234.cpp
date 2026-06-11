#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)


int main(){
    int H,W,N;
    cin>>H>>W>>N;
    int si,sj,is=1,ie=H,js=1,je=W; cin>>si>>sj;
    string S,T;
    cin>>S>>T;
    reverse(S.begin(),S.end());
    reverse(T.begin(),T.end());

    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            if(i==0 && j==0) continue;
            if(j==0){
                char c=T[i];
                if(c=='L') je=min(je+1,W);
                else if(c=='R') js=max(js-1,1);
                else if(c=='U') is=max(is-1,1);
                else ie=min(ie+1,H);
            }else{
                //cout<<1<<endl;
                char c=S[i];
                if(c=='L') js++;
                else if(c=='R') je--;
                else if(c=='U') ie--;
                else is++;
                if(js>W || je<1 || is>H || ie<1 || je-js<0 || ie-is<0){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            //cout<<is<<" "<<ie<<" "<<js<<" "<<je<<endl;
        }
    }
    si=H-si+1;
    if(is<=si && si<=ie && js<=sj && sj<=je) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


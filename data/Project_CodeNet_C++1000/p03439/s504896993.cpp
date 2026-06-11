#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll N, left=1,right;
    ll status[100000];
    cin>>N;
    right=N+1;
    MEMSET(status, 0);
    cout<<0<<endl<<flush;
    string s;
    cin>>s;
    if(s=="Vacant") return 0;
    if(s=="Male") status[1]=1;
    else status[1]=2;
    status[N+1]=status[1];
    while(true){
        ll next=(right-left)/2;
        //cout<<right<<sp<<left<<sp<<next<<endl<<flush;
        if(right-left<=1){
            cout<<right-1<<endl<<flush;
            cin>>s;
            if(s=="Vacant") return 0;
            cout<<left-1<<endl<<flush;
            cin>>s;
            if(s=="Vacant") return 0;
        }
        
        cout<<left+next-1<<endl<<flush;
        cin>>s;
        if(s=="Vacant") return 0;
        if(s=="Male") status[left+next]=1;
        else status[left+next]=2;
        if(next%2==0){
            if(status[left+next]==status[left])
                left+=next;
            else right=left+next;
        }
        else{
            if(status[left+next]==status[left])
                    right=left+next;
            else left+=next;
        }
        
    }
    return 0;
}
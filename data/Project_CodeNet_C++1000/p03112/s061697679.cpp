
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <type_traits>
#include <locale>
#include <omp.h>

using namespace std;
#define SAY_YES cout << "YES" << endl;
#define SAY_Yes cout << "Yes" << endl;
#define SAY_NO cout << "NO" << endl;
#define SAY_No cout << "No" << endl;
#define IFYES(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define IFYes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define IFyes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define DEBUG_OUTPUT_ARRAY(XXX, ONE)                            \
    for (int i = 0; i < (ONE); i++)                             \
    {                                                           \
        cout << "DEBUG: i = " << i << " -> " << XXX[i] << endl; \
    }
#define DEBUG_OUTPUT_ARRAY2(XXX, ONE, TWO)                             \
    for (int i = 0; i < (ONE); i++)                                    \
    {                                                                  \
        cout << "<<< i = " << i << " >>>" << endl;                     \
        for (int j = 0; j < (TWO); j++)                                \
        {                                                              \
            cout << "DEBUG: j = " << j << " -> " << XXX[i][j] << endl; \
        }                                                              \
    }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX, ONE, TWO) \
    for (int i = 0; i < (ONE); i++)            \
    {                                          \
        cout << i << "  ";                     \
        for (int j = 0; j < (TWO); j++)        \
        {                                      \
            cout << XXX[i][j] << " ";          \
        }                                      \
        cout << endl;                          \
    }

typedef pair<long long int, long long int> pll;
typedef pair<long long int, pll> lpll;

const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 
//const long long int pl=1000000;

long long int Q,A,B,s[200200],t[200200],x[200200];
int main(){
    cout << fixed << setprecision(18);
    cin>>A>>B>>Q;
    for(long long int i = 0; i < A; i++){
        cin>>s[i];
    }
    for(long long int i = 0; i < B; i++){
        cin>>t[i];
    }
    for(long long int i = 0; i < Q; i++){
        cin>>x[i];
    }
    for(long long int i = 0; i < Q; i++){
        long long int l=-1,r=A,mid,res=INF;
        while(r-l>1){
            mid=(r+l)/2;
            if(s[mid]<x[i]){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(l!=-1){
            long long int l2=-1,r2=B,mid2;
            while(r2-l2>1){
                mid2=(r2+l2)/2;
                if(t[mid2]<s[l]){
                    l2=mid2;
                }else{
                    r2=mid2;
                }
            }
            if(l2!=-1)res=min(res,abs(s[l]-x[i])+abs(s[l]-t[l2]));
            if(r2!=B)res=min(res,abs(s[l]-x[i])+abs(s[l]-t[r2]));
            
        }
        if(r!=A){
            
            long long int l2=-1,r2=B,mid2;
            while(r2-l2>1){
                mid2=(r2+l2)/2;
                if(t[mid2]<s[r]){
                    l2=mid2;
                }else{
                    r2=mid2;
                }
            }
            if(l2!=-1)res=min(res,abs(s[r]-x[i])+abs(s[r]-t[l2]));
            
            if(r2!=B)res=min(res,abs(s[r]-x[i])+abs(s[r]-t[r2]));
            
            
        }

        l=-1,r=B;
        while(r-l>1){
            mid=(r+l)/2;
            if(t[mid]<x[i]){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(l!=-1){
            long long int l2=-1,r2=A,mid2;
            while(r2-l2>1){
                mid2=(r2+l2)/2;
                if(s[mid2]<t[l]){
                    l2=mid2;
                }else{
                    r2=mid2;
                }
            }
            if(l2!=-1)res=min(res,abs(t[l]-x[i])+abs(t[l]-s[l2]));
            if(r2!=A)res=min(res,abs(t[l]-x[i])+abs(t[l]-s[r2]));
            
        }
        if(r!=B){
            long long int l2=-1,r2=A,mid2;
            while(r2-l2>1){
                mid2=(r2+l2)/2;
                if(s[mid2]<t[r]){
                    l2=mid2;
                }else{
                    r2=mid2;
                }
            }
            if(l2!=-1)res=min(res,abs(t[r]-x[i])+abs(t[r]-s[l2]));
            if(r2!=A)res=min(res,abs(t[r]-x[i])+abs(t[r]-s[r2]));
            
        }
        cout<<res<<endl;
    }
}


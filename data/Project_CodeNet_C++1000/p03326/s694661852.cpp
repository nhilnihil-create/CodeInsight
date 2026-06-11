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


const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 

long long int N,M,K,D,X,Y,x[200020],y[200020],z[200020],nokori,tmp,res=0,sum[200050]={};
long long int A[200678];

string str[1000];

int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>M;
    for(long long int i = 0; i < N; i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    for(long long int i = 0; i < 8; i++){
        long long int val[2010]={};
        for(long long int j = 0; j < N; j++){
            if((i&(1<<0))!=0){
                val[j]+=x[j];
            }else{
                val[j]-=x[j];
            }

            if((i&(1<<1))!=0){
                val[j]+=y[j];
            }else{
                val[j]-=y[j];
            }

            if((i&(1<<2))!=0){
                val[j]+=z[j];
            }else{
                val[j]-=z[j];
            }
        }
        long long int cou=0;
        sort(val,val+N,greater<long long int>());
        for(long long int i = 0; i < M; i++){
            cou+=val[i];
        }

        res=max(res,cou);
    }
    cout<<res<<endl;

}    

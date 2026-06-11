
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
long long int N,M,X,m[200200],res=0,k[40],s[30][30],p[30];


int main(){
    cout << fixed << setprecision(18);
    cin>>N>>M;
    for(long long int i = 0; i < M; i++){
        cin>>k[i];
        for(long long int j = 0; j < k[i]; j++){
            cin>>s[i][j];
            s[i][j]--;
        }
    }
    
    for(long long int i = 0; i < M; i++){
        cin>>p[i];
    }
    for(long long int bi = 0; bi < (1<<N); bi++){
        long long int Blight=0;
        for(long long int i = 0; i < M; i++){
            long long int switchCount=0;
            for(long long int j = 0; j < k[i]; j++){
                if(((1<<s[i][j])&bi)!=0){switchCount++;}
            }
            if(switchCount%2==p[i]){Blight++;}
        }
        if(Blight==M){res++;}
    }
    cout<<res<<endl;
}


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

long long int N,K,A[200],res=0,fin=0;

long long int type[200200]={},x=0;

priority_queue<pll,vector<pll>,greater<pll> >pq;
pll dt[200200];

int main(){
    cout << fixed << setprecision(18);
    cin>>N>>K;
    for(long long int i = 0; i < N; i++){
        cin>>dt[i].second>>dt[i].first;
    }
    sort(dt,dt+N,greater<pll>());
    for(long long int i = 0; i < K; i++){
        pq.push(dt[i]);
        res+=dt[i].first;
        
        if(type[dt[i].second]==0){
            x++;
        }
        type[dt[i].second]++;
    }
    fin=res+x*x;
    for(long long int i = K; i < N; i++){
        if(type[dt[i].second]>0){continue;}
        while(!pq.empty()&&type[pq.top().second]==1){
            pq.pop();
        }
        if(pq.empty()){
            cout<<fin<<endl;
            return 0;
        }
        res=res-pq.top().first+dt[i].first;
        type[pq.top().second]--;
        type[dt[i].second]++;
        x++;
        pq.pop();
        pq.push(dt[i]);
        fin=max(fin,res+x*x);
    }
    cout<<fin<<endl;
}



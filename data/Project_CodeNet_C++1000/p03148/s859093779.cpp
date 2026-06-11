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
const long long int INF = 99999999999999999;

long long int N,K,goal,t[110000],d[110000];
long long int used[110000]={},x=0,fin=0,tmp;
priority_queue<pll> pq;
priority_queue<pll,vector<pll>,greater<pll> > sushi;
vector<long long int>res;
int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>K;    
    for(long long int i = 0; i < N; i++){
        cin>>t[i]>>d[i];
        pq.push({d[i],t[i]});
    }
    tmp=0;
    for(long long int i = 0; i < K; i++){
        sushi.push(pq.top());
        tmp+=pq.top().first;
        if(used[pq.top().second]==0){
            x++;
            used[pq.top().second]++;
        }else{
            used[pq.top().second]++;
        }
        pq.pop();
    }
    fin=x*x+tmp;
    while(K!=res.size()&&!pq.empty()){
        if(used[sushi.top().second]==1){
            res.push_back(1);
            sushi.pop();
        }else{
            while(used[pq.top().second]!=0&&!pq.empty()){
                pq.pop();
            }
            if(pq.empty()){
                break;
            }
            tmp=tmp+pq.top().first-sushi.top().first;
            used[sushi.top().second]--;
            used[pq.top().second]++;
            sushi.pop();
            sushi.push(pq.top());
            x++;
            pq.pop();
            fin=max(fin,tmp+x*x);
        }
    }
    cout<<fin<<endl;
}

#include <bits/stdc++.h>
 
#define mp make_pair
 
using namespace std;
 
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef pair<i64,int> pli;
typedef pair<int,i64> pil;
typedef pair<i64,i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;
 
template <typename T>
T id(T b) {return b;};
template <class It>
bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It>
bool any(It f,It l){return std::any_of(f,l,id<bool>);}
 
const int MAX_N = 100;
int n;
double t[MAX_N+1];
double v[MAX_N+2];
//double b[MAX_N+1];
double b1[MAX_N+1];
double b2[MAX_N+1];
 
int main()
{
  cin >> n;
  t[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    t[i] += t[i-1];
  }
  v[0] = v[n+1] = 0;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 0; i <= n; i++) {
    b1[i] = min(v[i],v[i+1]) + t[i];
    b2[i] = min(v[i],v[i+1]) - t[i];
  }
  for (int i = 0; i <= n; i++) {
    b1[i] = *min_element(b1+i,b1+n+1);
    b2[i] = *min_element(b2,b2+i+1);
  }
 
  double d = 0;
  for (int i = 1; i <= n; i++) {
    double vs = min(-t[i-1]+b1[i-1], t[i-1]+b2[i-1]);
    double ve = min(-t[i]+b1[i], t[i]+b2[i]);
    //printf("vs=%f v[%d]=%f ve=%f\n",vs,i,v[i],ve);
    double dt = t[i] - t[i-1];
    double p = (ve+dt-vs) / 2.0;
    if (v[i] <= vs + p) {
      double mdt = dt - (v[i] - vs) - (v[i] - ve);
      double v1 = (v[i]+vs)*(v[i]-vs)/2.0;
      double v2 = mdt*v[i];
      double v3 = (v[i]+ve)*(v[i]-ve)/2.0;
      //printf("v1=%f v2=%f v3=%f\n",v1,v2,v3);
      d += v1 + v2 + v3;
    } else {
      d += (2.0*vs+p)*p/2.0 + (2.0*ve+dt-p)*(dt-p)/2.0;
    }
    //printf("i=%d d=%f\n",i,d);
  }
  printf("%.10f\n", d);
 
  return 0;
}
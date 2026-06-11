#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
using namespace std;
typedef long long ll;
 
int main() {
  int N; cin >> N;
  float t[N+2]={0}; for (int i=1; i<=N; i++) cin >> t[i];
  for (int i=1; i<=N+1; i++) t[i] += t[i-1];
  float v[N+2]={0}; for (int i=1; i<=N; i++) cin >> v[i];

  float v_min[2*(int)t[N+1]+1];
  memset(v_min, 0x7f, sizeof(v_min));

  for (int i=0; i<=2*(int)t[N+1]; i++) {
    float t_now = (float)i / 2;
    for (int j=0; j<=N+1; j++) {
      float s, e, v_tmp;
      if (j==0) s = t[j]; else s = t[j-1];
      e = t[j];
      if (s >= t_now) v_tmp = v[j] + ( s - t_now );
      else if (e <= t_now) v_tmp = v[j] + ( t_now - e );
      else v_tmp = v[j];
      v_min[i] = min(v_min[i], v_tmp);
    }
  }

  float result = 0;
  for (int i; i<ARRAY_LEN(v_min); i++) result += ( v_min[i] + v_min[i+1] ) * 0.25;
  cout << fixed << setprecision(10) << result << endl;
  return 0;
}
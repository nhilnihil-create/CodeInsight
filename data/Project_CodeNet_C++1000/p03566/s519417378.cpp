#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;
double yint(double sl, double x, double y){
    // y = sl*x+b
    return y-sl*x;
}
double herepos[20011];
double hereneg[20011];
int dists[20011];
int main ()
{
  prep();
  int n;
  cin >> n;
  for (int i=0; i<20011; i++){
    herepos[i] = 1000000000000000000;
    hereneg[i] = 1000000000000000000;
  }
  int t[n] = {0};
  int v[n] = {0};

  for (int i=0; i<n; i++){
      cin >> t[i];
  }
  for (int i=0; i<n; i++){
      cin >> v[i];
  }
  int dist = 0;
  
  herepos[0] = yint(1, 0, 0);
  for (int i=0; i<n; i++){
      hereneg[dist] = yint(-1, dist, v[i]);
      dists[dist] = i;
      dist += t[i];
      herepos[dist] = yint(1, dist, v[i]);
      dists[dist] = i;
      
  }
  hereneg[dist] = yint(-1, dist, 0);
  
  // go along decimal
  double lasth = 0;
  double curmax = 0;
  double sum = 0;

  for (int ii=0; ii<=dist*2; ii++){
     double i = ii/2.0;
     double minneg = 1000000000000000000;
 	 double minpos = 1000000000000000000;
      for (int j=0; j<=ii/2; j++){
        minpos = min(minpos, herepos[j]);
        if (herepos[j] != 1000000000000000000){
            curmax = v[dists[j]];
        }
        
      }
      for (int j=ii/2+ii%2; j<=dist; j++){
      
        minneg = min(minneg, hereneg[j]);
      }
    
      double h = min(minpos+i, min(minneg-i, curmax)); 
    //cout << h << endl;
      double ych = abs(lasth-h);
    
      sum += ych*.5/2+min(h, lasth)*.5;
      //cout << sum << endl;
      lasth = h;
      
  }
  printf("%.18lf", sum);
  return 0; 
}

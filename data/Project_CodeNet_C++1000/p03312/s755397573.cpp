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
long long arr[200000];
int ternsearch(int l, int r){
    int origr = r;
    int origl = l;
    r--;
   int lastmid1 = -1;
   int lastmid2 = -1;
   int mid1 = 0;
   int mid2 = 0;
   while (true){
     mid1 = (r-l)/3+l;
     mid2 = r-(r-l)/3;
     if (mid1 == lastmid1 && mid2 == lastmid2){
       break;
     }
     long long sum1r = arr[origr]-arr[mid1];
     
     long long sum2r = arr[origr]-arr[mid2];
     long long sum1l, sum2l; 
     if (origl == 0){
         sum1l = arr[mid1];
         sum2l = arr[mid2];
     }else{
         sum1l = arr[mid1]-arr[origl-1];
         sum2l = arr[mid2]-arr[origl-1];
     }
     
     if (abs(sum1l-sum1r) > abs(sum2l-sum2r)){
       l = mid1+1;
     }else if (abs(sum1l-sum1r) < abs(sum2l-sum2r)){
       r = mid2-1;
     }else{
       l = mid1;
     }
     lastmid1 = mid1;
     lastmid2 = mid2;
   }
   return lastmid1;
}
int main(){
  prep();
  int n;
  cin >> n;
  
  for (int i=0; i<n; i++){
      cin >> arr[i];
  }
  for (int i=1; i<n; i++){
      arr[i] = arr[i]+arr[i-1];
  }
  long long minn = 1000000000000000000LL;
  for (int i=1; i<n-2; i++){
      // in the space after element i
      int lastgood1 = ternsearch(0, i);
      int lastgood2 = ternsearch(i+1, n-1);
      long long sum1 = arr[lastgood1];
      long long sum2 = arr[i]-arr[lastgood1];
      long long sum3 = arr[lastgood2]-arr[i];
      long long sum4 = arr[n-1]-arr[lastgood2];
      long long lst[4] = {sum1, sum2, sum3, sum4};
      sort(lst, lst+4);
      //cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
      minn = min(minn, lst[3]-lst[0]);
  }
  cout << minn;
  return 0; 
}
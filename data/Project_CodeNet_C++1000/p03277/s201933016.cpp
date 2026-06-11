#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.);
const long long mod = 998244353;
typedef long long ll;
const double eps = 1e-10;
//printf("%.12lf\n",mid);
//const long long sze = 2*(2^(long long)(ceil(log(100000)/log(2))));
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
long long lcm(long long a, long long b){
  return (a*b)/gcd(a, b);
}
inline void prep()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
};
long long modpow(long long x, long long n) { 
  if (n == 0) return 1%mod; 
  long long u = modpow(x,n/2); 
  u = (u*u)%mod; 
  if (n%2 == 1) u = (u*x)%mod; 
  return u;
}
 
long long modpow2(long long x, long long n, long long modd) { 
  if (n == 0) return 1LL%modd; 
  long long u = modpow2(x,n/2LL, modd); 
 
  u = (long long)(u*u)%modd; 
  if (n%2LL == 1) u = (long long)(u*x)%modd; 
  return u;
}
 
bool chosen[1001]={false};

vector<int> permutation;

void search(int n) {
  if (permutation.size() == n) {
    
  } else {
    for (int i = 0; i < n; i++) {
      if (chosen[i]) continue;
      chosen[i] = true;
      permutation.push_back(i);
      search(n);
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

vector<long long> primeFactors(long long n)
{
    // Print the number of 2s that divide n
    vector<long long> res;
    bool found = false;
    while (n%2 == 0)
    {
      found = true;
        n = n/2;
    }
    if (found){
      res.push_back(2);
    }
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
      
        // While i divides n, print i and divide n
        bool found2 = false;
        while (n%i == 0)
        { 
          found2 = true;
            n = n/i;
        }
        if (found2){
          res.push_back(i);
        }
    }

    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        res.push_back(n);
    return res;
}
vector<long long> getprimes(long long N){

  int is_prime[N+1];

  /* initialize */
  for (int i = 1; i <= N; i++)
      is_prime[i]=1;

  /* 1 is not a prime */
  is_prime[1]=0;


  for (int i = 2; i*i <= N; i++)
      if (is_prime[i])
          for (int j = i; j*i <= N; j++)
              is_prime[j*i]=false;
  
  /* print every prime <= N */
  vector<long long> lst;
  for (int i = 1; i <= N; i++)
      if (is_prime[i])
          lst.push_back(i);
  return lst;
}
int myXOR(int x, int y)
{
   return (x | y) & (~x | ~y);
}
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
long long count(int arr[], int l[], int r[], int s1, int s2){
  int i=0;
  int j=0;
  long long cnt = 0;
  while (i < s1 || j < s2){
    if (i == s1){
      arr[i+j] = r[j];
      j++;
    }else if (j == s2){
      
      arr[i+j] = l[i];
      i++;
    }else if (l[i] <= r[j]){
      arr[i+j] = l[i];
      i++;
    }else{
      cnt += s1-i;
      arr[i+j] = r[j];
      j++;
    }
  }
  return cnt;
}
long long counter(int arr[], int sz){
  
  if (sz == 1){
    if (arr[0] < 0){
      //cout << arr[0] << endl;
      return 1;
    }
    return 0;
  }
  int thiss = sz/2+1;
  int l[thiss];
  int r[thiss];
  int s1 = 0;
  int s2 = 0;
  for (int i=0; i<sz/2; i++){
    l[i] = arr[i];
    
    s1++;
  }
  for (int i=sz/2; i<sz; i++){
    r[s2] = arr[i];
    
    s2++;
  }
  return counter(l, s1)+counter(r, s2)+count(arr, l, r, s1, s2);
}
int main(){
  prep();
  vector<int> nums;
  vector<int> nums2;
  long long n;
  cin >> n;
  for (int i=0; i<n; i++){
    int num;
    cin >> num;
    nums.push_back(num);
    nums2.push_back(num);
  }
  
  long long intervals = n*(n+1)/2;
  sort(nums2.begin(), nums2.end());
  int l = 0;
  int r = n-1;
  // binary search if the number is the median, if it is, the num
  // intervals less than the number will be the closest one to
  // intervals/2, but it has to be under it
  int lastover = 0;
  while (l <= r){
    int mid = (l+r)/2;
    int currnum = nums2[mid];
    int temp[n];
    for (int i=0; i<n; i++){
      temp[i] = nums[i];
    }
    for (int i=0; i<n; i++){
      if (temp[i] < currnum){
        temp[i] = -1;
      }else{
        temp[i] = 1;
      }
    }
    for (int i=1; i<n; i++){
      temp[i] = temp[i]+temp[i-1];
      
    }
    // i-j
    
   
    // find spaces where temp[i] > temp[j] and i < j
    /*for (int i=0; i<n; i++){
      cout << temp[i] << " ";
      
    }
    cout << endl;*/
    long long res = counter(temp, nums.size());
    /*
    for (int i=0; i<n; i++){
      cout << temp[i] << " ";
      
    }
    cout << endl;*/
    /*cout << res << endl;
    cout << currnum << endl;*/
    if (res < intervals/2+1){
      lastover = currnum;
      l = mid+1;
    }else{
      r = mid-1;
    }
    
    
  }
  cout << lastover;
}
// run examples of solution before writing it
// if TLE think about switching or removing loops & try not to use vector functions like size() or create new vector in a loop
// never use brackets with map when accessing value
// if super stuck try to find a pattern
// if getting error for no reason check if everything is long long
// if can't think of anything efficient try brute force
// look at solved problems of other ppl 2 see which is easiest
// if can precompute 
// if getting random error w/ loop check if boundaries are being changed during loop
// if you can't solve any more problems check for hacks in ur code then hack 
// in reversing problems if checking for a pattern use write down indices
// if already sure about wrong answers check TLE
// in geom problems working with decimals use eps for equals
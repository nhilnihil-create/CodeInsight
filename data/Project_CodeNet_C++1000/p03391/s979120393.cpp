#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

//template<class T, size_t N> 
//size_t countof(const T (&array)[N]) { return N; }

int main() {
  int N;
  cin >> N;
  long long int a[N], b[N];

  for (int i=0; i < N; i++ ){
    cin >> a[i] >> b[i];
  }

  //  sort(a, a+N);
  //  sort(b, b+N);

  //  int ans=0;
  long long int sum=0;
  long long int min_tozan =INT_MAX;
  int flag=0;
  for (int i=0; i < N; i++ ){
    /*    if(a[i] <= b[i]){
      ans += a[i];
    }
    else{*/
    if(a[i] > b[i]){ 
      min_tozan =min(min_tozan, b[i]);
      flag=1;
    }
    sum += a[i];
  }
  
  if(flag==0){
    cout << 0 << endl;
    return 0;
  }
  else{
    cout << (sum - min_tozan) << endl;
  }

}

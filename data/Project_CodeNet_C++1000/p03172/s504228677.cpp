#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int main()
{
  int n = 0;
  int k = 0;
  long long base = 1e9+7;
  scanf("%d %d", &n, &k);
  if(k == 0){
    printf("1\n");
    return 0;
  }
  vector<int> a(n, 0);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int good_cnt = 0;
  for(int i=0; i<n; i++){
    if(a[i] > 0){
      a[good_cnt] = a[i];
      good_cnt++;
    }
  }
  n = good_cnt;
  long long arr[n][k+1];
  memset(arr, 0, sizeof arr);
  for(int j=0; j<k+1; j++){
    if(j >= a[0]){
      arr[0][j] = a[0]+1;
    }else{
      arr[0][j] = j+1;
    }
  }
  for(int i=1; i<n; i++){
    for(int j=0; j<k+1; j++){
      if(j <= a[i]){
        arr[i][j] = arr[i-1][j];
      }else{
        arr[i][j] = (arr[i-1][j] - arr[i-1][j-a[i]-1] + base ) % base;
      }
    }
    for(int j=1; j<k+1; j++){
      arr[i][j] = (arr[i][j] + arr[i][j-1]) % base;
    }
  }
//  for(int i=0; i<n; i++){
//    for(int j=0; j<k+1; j++){
//      printf("%lld ", arr[i][j]);
//    }
//    printf("\n");
//  }
  printf("%lld\n", (arr[n-1][k] - arr[n-1][k-1] + base) % base);
}

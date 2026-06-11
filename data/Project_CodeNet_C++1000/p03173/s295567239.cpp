#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int main()
{
  int n = 0;
  scanf("%d", &n);
  vector<int> a(n, 0);
  vector<long long> sum_a(n+1, 0);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  long long arr[n][n];
  long long curr_best = 0;
  memset(arr, 0, sizeof arr);
  for (int i=0; i<n; i++){
//    arr[i][i] = a[i];
    sum_a[i+1] = sum_a[i] + a[i];
  }
  for (int j=1; j<n; j++){
    for (int i=0; i+j<n; i++){
      curr_best = arr[i][i] + arr[i+1][i+j];        
      for (int k=i+1; k<i+j; k++){
        if(arr[i][k] + arr[k+1][i+j] < curr_best){
          curr_best = arr[i][k] + arr[k+1][i+j];
        }
      }
      arr[i][i+j] = curr_best + sum_a[i+j+1] - sum_a[i];
    }
  }
  printf("%lld\n", arr[0][n-1]);
  

//  for(int i=0; i<n; i++){
//    for(int j=0; j<n; j++){
//      printf("%lld ", arr[i][j]);
//    }
//    printf("\n");
//  }
}

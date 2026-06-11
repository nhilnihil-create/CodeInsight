#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x=0,y=0,z=0,l=0,m=0;
  int p[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
  int n;
  cin >> n;
  int a[16];
  fill(a,a+16,0);
  
  for (int i = 2; i <= n; i++) {
    int j = 0, temp = i;
    while (temp > 1 && j < 15) {
      if (temp%p[j]) j++;
      else {
        temp /= p[j];
        a[j]++;
      }
    }
  }

  for(int i=0;i<15;i++){
   if(a[i]>=2){
     x++;
   }
   if(a[i]>=4){
     y++;
   }     
   if(a[i]>=14){
     z++;
   }   
   if(a[i]>=24){
     l++;
   } 
   if(a[i]>=74){
     m++;
   }   
 }
	cout << m + l * (x - 1) + z * (y - 1) + y * (y - 1) / 2 * (x - 2) << endl;
	return 0;
}

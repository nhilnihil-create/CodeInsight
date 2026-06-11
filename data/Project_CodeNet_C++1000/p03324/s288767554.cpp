#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

int main(){
   int d, n;
   cin >> d >> n;
   int cnt = 0;
   for(int i = 1; ; i++){
      
       	int temp = 0, foo = i;
       	while(foo > 0){
       	 	if(foo%100 == 0)foo /= 100;
       	 	else break;
       	 	temp++;
       	}
       	if(temp == d)cnt++;
         if(cnt == n){
          	cout << i << endl; return 0;
         }
   }	   
	return 0;
}                  

#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a,b;
cin >>n>>a>>b;
int ans=0;
for(int i=1;i<n+1;i++){
int sum = 0;
int num = i;
while(num/10 >=1){
sum+= num%10;
num = num / 10;
}
sum += num;
if(sum >= a && sum <= b)
ans += i;
}
cout << ans <<endl; 
}


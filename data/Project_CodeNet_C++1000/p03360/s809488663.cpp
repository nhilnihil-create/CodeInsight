#include<iostream>
#define ll long long

int main(){
int a,b,c,k;
 std::cin >> a >> b >> c >> k;
 int max = std::max(a,std::max(b,c));
 int t=0;
 t = max;
 for(int i=1;i<=k;i++){
    t*=2;
 }
 if(max==a) std::cout << t+b+c;
 else if(max==b) std::cout << t+a+c;
 else if(max==c) std::cout << t+b+a;
 return 0;
}

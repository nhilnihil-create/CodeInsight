#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int sum_digit(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int digit(int n){
    while( n >= 10 ) n = sum_digit(n);
    return n;
}


int gcd(int x, int y){
    return x % y == 0 ? y : gcd(y, x % y);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

bool prime_judge(int n){
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    double sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) if (n % i == 0) return false;
    return true;
}

int binary_search(vi a,int key){
    int n = a.size();
    int left = 0, right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(a[mid] == key) return mid;
        else if(a[mid] > key) right = mid;
        else left = mid + 1;
    }
    return -1;
}

vi ITV(int bit, int n){
   vi S;
   Srep(n){
       if(bit & (1<<i)){
           S.push_back(i);
       }
   }
   return S;
}

int main(){
	int r,d,x,ans;
    cin>>r>>d>>x;
  	ans=x;
  	for(int i=0;i<10;i++){
    	ans=ans*r-d;
      	cout<<ans<<endl;
    }
}
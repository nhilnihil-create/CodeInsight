#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int somarDigitos(int numero) {
    int soma = 0;

    while (numero != 0) {
        soma   += numero % 10;
        numero  = numero / 10;
    }

    return soma;
}

int main() {

    ios::sync_with_stdio(false);
    
  	int a, b, n,ans;
  	
  	cin >> n;
  	
  	a=1;
  	b=n-a;
  	ans=somarDigitos(a)+somarDigitos(b);
  	
  	while(a<=b){
  		
  		a++;
  		b--;
		if(ans>somarDigitos(a)+somarDigitos(b)){
			ans=somarDigitos(a)+somarDigitos(b);				
			}
		}
	cout << ans << endl;
	
	
  	
  	
    return 0;
}
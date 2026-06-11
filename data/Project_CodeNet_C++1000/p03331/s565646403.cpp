#include <bits/stdc++.h>
using namespace std;

int calcula(int n){
	if(n < 10)
		return n;
	else
		return n%10 + calcula(n/10); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int menor = 100001;
    for (int i = 1; i < n; ++i){
    	int resto = n - i;
    	menor = min(menor,(calcula(i)+calcula(resto)));
    }
    cout << menor << endl;
    return 0;
}
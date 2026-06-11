#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	long long int n, a1, b;
	cin >> n >> a1 >> b;
	int flag = 0;
	if(n == a1){
		if(b == 1){
			for(int i = 0; i < n; i++){
				cout << i+1 << " ";
			}
			cout << '\n';
			return 0;
		}
		else{
			flag = 1;
		}
	}
	if(n == b){
		if(a1 == 1){
			for(int i = 0; i < n; i++){
				cout << n-i << " ";
			}
			cout << "\n";
			return 0;
		}
		else{
			flag = 1;
		}
	}
	if(a1 == 1 && b != n) flag = 1;
	if(a1 != n && b == 1) flag = 1;
	if(a1 > n || b > n){
		flag = 1;
	}
	if(flag == 1){
		cout << "-1\n";
		return 0;
	}
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = i;
	}
	for(int j = 0; j < b; j++){
		if(j > b-1-j){
			break;
		}
		swap(a[j], a[b-1-j]);
	}
	int x = 1;
	int rem = a1-1;
	int div = (n-b)/rem;
	int count = (n-b)%rem;
	if(div > b){
		cout << "-1\n";
		return 0;
	}
	// cout << "hi\n";
	// cout << div << " " << count << '\n';
	for(int i = b; i < n;){
		x++;
		int l = n - i;
		long long int size = div; 
		if(count > 0){
			size = min(size+count, b);
			count -= size - div;
		}
		for(int j = 0; j < size; j++){
			if(i+j > min(n,i+size)-1-j){
				break;
			}
			swap(a[i+j], a[min(n,i+size)-1-j]);
		}
		i += size;
	}
	// cout << x << '\n';
	if(x != a1){
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++){
		cout << a[i]+1 << ' ';
	}
	cout << '\n';
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	string code;
	cin >> code;
	if(code[a]!='-'){
		cout << "No\n";
		return 0;
	}
	else{
		int i;
		bool flag = true;
		for(i=0; i<=(a+b); i++){
			if(i!=a){
				if(code[i]>='0' && code[i]<='9') continue;
				else{
					flag = false;
					break;
				}
			}
		}
		if(flag){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}

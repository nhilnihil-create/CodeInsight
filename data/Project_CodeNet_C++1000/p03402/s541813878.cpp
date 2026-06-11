	#include<bits/stdc++.h>
	using namespace std;

	char grid[100][100];

	int main(){
		int a,b;
		cin>>a>>b;

		for(int i = 0;i<50;i++){
			for(int j = 0; j<100;j++){
				grid[i][j] = '#';
			}
		}


		for(int i = 50;i<100;i++){
			for(int j = 0; j<100;j++){
				grid[i][j] = '.';
			}
		}

		for(int i = 0;i < 50 && a-1>0;i+=2){
			for(int j = 0; j<100 && a-1>0;j+=2){
				grid[i][j] = '.';
				a--;
			}
		}


		for(int i = 51;i < 100 && b-1>0;i+=2){
			for(int j = 0; j<100 && b-1>0;j+=2){
				grid[i][j] = '#';
				b--;
			}
		}
		cout<<100<<" "<<100<<endl;
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100;j++){
				cout<<grid[i][j];
			}
			cout<<endl;
		}

	}
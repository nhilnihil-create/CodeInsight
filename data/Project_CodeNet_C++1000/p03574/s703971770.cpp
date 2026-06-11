#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

pair<int,int> directions[8]={{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}} ;

bool valid(int x,int y,int h,int w){
	return x>=0 && y>=0 && x<h && y<w ;
}

void solve(){
	
	int h,w ;
	cin>>h>>w ;

	char arr[h][w] ;

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>arr[i][j] ;
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){

			if(arr[i][j]!='#'){	
				int count=0 ;
			for(auto dir:directions){

				int r=i+dir.first ;
				int c=j+dir.second ;

				if(valid(r,c,h,w) && arr[r][c]=='#')
					count++ ;

			}

			arr[i][j]=count+'0' ;

			}
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<arr[i][j] ;
		}
		cout<<"\n" ;
	}


}	

int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}
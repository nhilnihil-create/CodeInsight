#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000

/*方針*/
/*
➀a[i][j]を全探索するが、iはどんどん右へ、jはどんどん下へ移動する。
➁この時、a[i][j]が奇数なら、一個コインを右か下にずらす。
➂上記のようにして偶数マスを増やしていく(余ったコインを右下に追い込む)
*/
int main(){
	int h,w;cin>>h>>w;
	vector<vector<int>> a(h,vector<int>(w,0));
	for(int i=0;i<h;i++){//input
		for(int j=0;j<w;j++){
			cin>>a[i][j];
		}
	}

	vector<pair<int,int>> Pbefore,Pafter;//coinの移動前と後
	int did=0;

	int dx[2]={1,0},dy[2]={0,1};//右or下
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<2;k++){
				if(i+dy[k]<0 || i+dy[k]>=h || j+dx[k]<0 || j+dx[k]>=w) continue;//枠外

				if(a[i][j]%2==1){//a[i][j]が奇数ならcoinを右か下へ
					a[i][j]--;
					a[i+dy[k]][j+dx[k]]++;
					did++;//coin移動回数加算
					Pbefore.push_back(make_pair(i,j));//移動前座標
					Pafter.push_back(make_pair(i+dy[k],j+dx[k]));//移動後座標
				}
			}
		}
	}

	cout<<did<<endl;//coin移動回数
	for(int i=0;i<Pafter.size();i++){//座標を表示
		cout<<Pbefore[i].first+1<<" "<<Pbefore[i].second+1<<" ";
		cout<<Pafter[i].first+1<<" "<<Pafter[i].second+1<<endl;
	}

	return 0;
}
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    vector<vector<int>> data(3,vector<int>(3));
    int sum = 0;
    rep(i,0,3){
        rep(j,0,3){
            cin >> data[i][j];
            sum += data[i][j];
        }
    }
    if(sum%3!=0){
        cout<<"No"<<endl;
        return 0;
    }

    vector<int> height(3);
    vector<int> width(3);
    rep(i,0,3){
        rep(j,0,3){
            height[i]+=data[i][j];
        }
    }
    rep(i,0,3){
        rep(j,0,3){
            width[i]+=data[j][i];
        }
    }

    if((height[0]-height[1])%3==0&&(height[2]-height[0])%3==0&&(width[0]-width[1])%3==0&&(width[2]-width[0])%3==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    

  return 0;
}
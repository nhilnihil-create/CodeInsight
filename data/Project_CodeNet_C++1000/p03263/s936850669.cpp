#include<bits/stdc++.h>
using namespace std;
int main(){
int h ,w;
cin>>h>>w;

vector<pair<int,int> >fst;
vector<pair<int,int> >scnd;

int grid[h][w];
int sum = 0;
for(int i=0 ; i<h ; i++){
    for(int j=0 ; j<w ; j++){
        cin>>grid[i][j];
        sum += grid[i][j];
    }
}


for(int i=0 ; i<h ; i++){
    if(i%2==0){
    for(int j=0 ; j<w-1 ; j++){
       if(grid[i][j] % 2){
        grid[i][j+1] += grid[i][j];
        fst.push_back({i+1 , j+1});
        scnd.push_back({i+1, j+2});
       }
    }
    if(grid[i][w-1]%2 && i+1<h){
        grid[i+1][w-1] += grid[i][w-1];
        fst.push_back({i+1 , w});
        scnd.push_back({i+2 ,w});
    }
    }

    else{
    for(int j=w-1 ; j>=1 ; j--){
        if(grid[i][j] % 2){
        grid[i][j-1] += grid[i][j];
        fst.push_back({i+1 , j+1});
        scnd.push_back({i+1, j});
       }
    }
    if(grid[i][0]%2 && i+1<h){
        grid[i+1][0] += grid[i][0];
        fst.push_back({i+1 , 1});
        scnd.push_back({i+2 ,1});
    }

    }

}

/*for(int i=0 ; i<h ; i++){
    for(int j=0 ; j<w; j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<endl;
}


cout<<endl<<endl;*/


cout<<fst.size()<<endl;
for(int i=0 ; i<fst.size() ; i++){
    cout<<fst[i].first<<" "<<fst[i].second<<" ";
    cout<<scnd[i].first<<" "<<scnd[i].second<<endl;
}

}

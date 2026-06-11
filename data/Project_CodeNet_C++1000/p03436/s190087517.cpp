#include <iostream>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define move(i) for(int i=-1;i<=1;i+=2)
#define WHITE 0
#define GRAY 1 
#define BLACK 2
#define INF 1e9

using namespace std;
using P = pair<int,int>;

int h,w,M[50][50],C[50][50],D[50][50];

int main()
{
    int black=0;
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            char s;
            cin>>s;

            if(s=='.'){
                M[i][j] = 0;
            }else{
                M[i][j] = 1;
                black++;
            }

            C[i][j]=WHITE;
            D[i][j]=INF;
        }
    }

    //BFS
    queue<P> Q;
    D[0][0]=1;
    C[0][0]=GRAY;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        P p=Q.front(); Q.pop();
        //cout <<"~("<< p.first << "," << p.second << ")~"<<endl;
        move(x){
            int i=p.first+x, j=p.second;
            //cout <<"("<< i << "," << j << ")"<<endl;
            if((i>=0)&&(i<h)&&(j>=0)&&(j<w) ){
                //cout << M[i][j] << "," << C[i][j] << endl;
                if(M[i][j]==0 && C[i][j]==WHITE){
                    C[i][j]=GRAY;
                    D[i][j]=D[p.first][p.second]+1;
                    Q.push(make_pair(i,j));
                }
            }
        }

        move(y){
            int i=p.first, j=p.second+y;
            //cout <<"("<< i << "," << j << ")"<<endl;
            if((i>=0)&&(i<h)&&(j>=0)&&(j<w) ){
                //cout << M[i][j] << "," << C[i][j] << endl;
                if(M[i][j]==0 && C[i][j]==WHITE){
                    C[i][j]=GRAY;
                    D[i][j]=D[p.first][p.second]+1;
                    Q.push(make_pair(i,j));
                }
            }
        }

    }
    if(D[h-1][w-1]==INF){
        cout << -1 << endl;
    }else{
        cout << h*w-D[h-1][w-1]-black << endl;
    }



    return 0;
}

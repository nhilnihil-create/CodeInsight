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

int h,w,M[1010][1010],C[1010][1010],D[1010][1010];
queue<P> Q;

int main()
{
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            char s;
            cin>>s;

            if(s=='.'){
                M[i][j] = 0;
                C[i][j]=WHITE;
                D[i][j]=INF;
            }else{
                M[i][j] = 1;
                C[i][j]=GRAY;
                D[i][j]=0;
                Q.push(make_pair(i,j));
            }
        }
    }

    //BFS
    int last_d=0;
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
                    last_d=D[i][j]=D[p.first][p.second]+1;
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
                    last_d=D[i][j]=D[p.first][p.second]+1;
                    Q.push(make_pair(i,j));
                }
            }
        }

    }

    cout << last_d << endl;


    return 0;
}

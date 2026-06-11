#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

/////////////////////////////////////////////////////
#define pii pair<int,int>
#define mkp make_pair

int H,W,N,X[202020],Y[202020];
vector<pii> XYv;

int wall[202020];
int i,j,h;
int main(){
    scanf("%d%d%d",&H,&W,&N);
    fornum (i,0,N){
        scanf("%d%d", &X[i],&Y[i]);
        XYv.push_back(mkp(X[i], Y[i]));
    }
    sort(XYv.begin(), XYv.end());

    h = 0;
    fornum(i, 1, H+1){
        while(j<XYv.size()&&XYv[j].first==i){
            if(XYv[j].second<=h){
                printf("%d", i-1);
                return 0;
            }
            wall[XYv[j].second] = i;
            j++;
        }
        if(wall[h+1]!=i){
            h++;
        }
    }

    printf("%d", H);
    return 0;
}
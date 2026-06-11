#include <iostream>
#include <vector>

using namespace std;

bool f1[4123][32123],f2[4123][32123];
int b=16000;
vector<int> ex,ey;

int main(){
    string s;
    int cur=1,ls=0;
    int nx=0,ny=0;
    int x,y;
    cin>>s>>x>>y;
    for(int i=0;i<s.size();++i){
        if(s[i]=='T'){
            if(ls>0){
                if(cur){
                    ex.push_back(ls);
                    nx+=ls;
                }
                else {
                    ey.push_back(ls);
                    ny+=ls;
                }
            }
            ls=0;
            cur^=1;
        }else ++ls;
    }
    if(ls>0){
                if(cur){
                    ex.push_back(ls);
                    nx+=ls;
                }
                else {
                    ey.push_back(ls);
                    ny+=ls;
                }
            }
    f1[0][b]=1;
    for(int i=0;i<ex.size();++i)
        for(int j=b-nx;j<=b+nx;++j)
            if(i||s[0]!='F')f1[i+1][j]=f1[i][j-ex[i]]|f1[i][j+ex[i]];
            else f1[i+1][j]=f1[i][j-ex[i]];
    f2[0][b]=1;
    for(int i=0;i<ey.size();++i)
        for(int j=b-ny;j<=b+ny;++j)
            f2[i+1][j]=f2[i][j-ey[i]]|f2[i][j+ey[i]];
    if(f1[ex.size()][x+b]&&f2[ey.size()][y+b])cout<<"Yes";
        else cout<<"No";
    return 0;
}

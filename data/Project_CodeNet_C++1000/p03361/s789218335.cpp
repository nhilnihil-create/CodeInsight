#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;

    vector<string> v(h);

    for(size_t i=0;i<v.size();i++){
        cin >> v.at(i);
    }

    bool ans =true;

    for(size_t y=0;y<v.size();y++){

        for(size_t x=0;x<v.at(y).size();x++){
            bool judge=true;
            if(v.at(y).at(x)=='#'){

                judge=false;
                for(int dy =-1;dy<=1;dy+=2){
                    int ny=y+dy;
                    if(ny==-1||ny==h)
                        continue;
                    if(v.at(ny).at(x)=='#')
                        judge=true;
                }
                for(int dx =-1;dx<=1;dx+=2){
                    int nx=x+dx;
                    if(nx==-1||nx==w)
                        continue;
                    if(v.at(y).at(nx)=='#')
                        judge=true;
                }
            }

            if(!(judge))
                ans=false;
        }
    }

    if(ans) cout << "Yes"<<endl;
    else    cout << "No"<<endl;

}
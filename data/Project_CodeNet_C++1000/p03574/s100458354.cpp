#include<iostream>
#include<string>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    string s[h];
    for(int i=0;i<h;i++)cin>>s[i];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#')cout<<'#';
            else{
                int cnt=0;
                for(int x1=-1;x1<=1;x1++){
                    for(int x2=-1;x2<=1;x2++){
                        if(i+x1<0||i+x1>=h||j+x2<0||j+x2>=w)continue;
                        if(s[i+x1][j+x2]=='#')cnt++;
                    }
                }
                cout<<cnt;
            }
        }
        cout<<endl;
    }
    return 0;
}
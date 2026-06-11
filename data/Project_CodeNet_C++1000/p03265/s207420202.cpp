#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define point complex<long long>
#define pi acos(-1)
#define pb push_back


typedef long long ll;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
double dis(int x1, int x2, int y1, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool check(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4){
    double res1, res2, res3, res4;
    res1=dis(x1, x2, y1, y2);
    res2=dis(x2, x3, y2, y3);
    res3=dis(x3, x4, y3, y4);
    res4=dis(x4, x1, y4, y1);
    double res5, res6;
    res5=dis(x1, x3, y1, y3);
    res6=dis(x2, x4, y2, y4);
    return (res1==res2 && res1==res3 && res1==res4 && res5==res6 && (sqrt(2*res1*res1))==res5);
}
int main()
{
    Fastio();
    int ttt=1; //cin>>ttt;
    while(ttt--){
        ll x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        /*for(int x3=-1000; x3<=1000; x3++){
            for(int y3=-1000; y3<=1000; y3++){
                if(x1==x3 && y1==y3)continue;
                int x4=x3+abs(x1-x2), y4=y3+abs(y1-y2);
                bool st=0;
                st=check(x1, x2, x3, x4, y1, y2, y3, y4);
                if(st)return cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<'\n', 0;

                x4=x3+abs(x1-x2), y4=y3-abs(y1-y2);
                st=check(x1, x2, x3, x4, y1, y2, y3, y4);
                if(st)return cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<'\n', 0;

                x4=x3-abs(x1-x2), y4=y3-abs(y1-y2);
                st=check(x1, x2, x3, x4, y1, y2, y3, y4);
                if(st)return cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<'\n', 0;

                x4=x3-abs(x1-x2), y4=y3+abs(y1-y2);
                st=check(x1, x2, x3, x4, y1, y2, y3, y4);
                if(st)return cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<'\n', 0;
            }
        }*/
        int dx=x2-x1, dy=y2-y1;
        cout<<x2-dy<<" "<<y2+dx<<" "<<x1-dy<<" "<<y1+dx<<'\n';
    }

    return 0;
}

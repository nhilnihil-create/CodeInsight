#include <iostream>
#include <algorithm>
using namespace std;
const int N=200000+10;

int h,w,n;
pair<int,int> p[N];

int main(){
    scanf("%d%d%d",&h,&w,&n);
    int ans=h;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].first,&p[i].second);
    } sort(p+1,p+1+n);

    int low=-1;
    for(int i=1;i<=n;i++){
        if(p[i].first>=p[i].second){
            int d=p[i].first-p[i].second;
            if(d==low+1) {
                low++;
            } else if(d>low+1) {
                ans=min(ans,p[i].first-1);
            }
        }
    }

    printf("%d\n", ans);
}

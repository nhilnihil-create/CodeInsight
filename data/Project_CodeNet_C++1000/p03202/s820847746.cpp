#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n;
int a[200005];
vector<ii> s;
bool test(int x){
    //printf("test %d\n",x);
    s.clear();
    for (int i = 1; i <= n; i++){
        //printf("now %d\n",a[i]);
        if (a[i] > a[i-1]){
            s.push_back(ii(a[i]-a[i-1],0));
        }
        else{
            int num = a[i-1];
            while (num > a[i]){
                ii cur = s.back(); s.pop_back();
                int d = cur.first, ch = cur.second;
                if (num-d < a[i]){
                    s.push_back({d-num+a[i],ch});
                    num = a[i];
                }
                else{
                    num -= d;
                }
            }
            int ct = 0;
            while (s.size() && s.back().second == x-1){
                ct += s.back().first;
                s.pop_back();
            }
            if (s.size() == 0) return false;
            int pct = s.back().first, pid = s.back().second; s.pop_back();
            if (pct-1) s.push_back({pct-1,pid});
            s.push_back({1,pid+1});
            if (ct) s.push_back({ct,0});
        }

        for (auto x : s){
            //printf("%d %d\n",x.first,x.second);
        }
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for (int i = 1 ; i <= n; i++){
        scanf("%d",&a[i]);
    }
    int lo = 1, hi = n;
    while (lo < hi){
        int mid = (lo+hi)/2;
        if (test(mid)){
            hi = mid;
        }
        else lo = mid+1;
    }
    printf("%d",lo);

}


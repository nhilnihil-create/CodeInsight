#include<cstdio>
#include<algorithm>
#include<set>
int const maxN=200001;
int op[maxN];
std::set<int> ops[maxN];
int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ops[y].emplace(x);
    }
    int offset=0;
    for(int i=1;i<=w;i++){
        while(ops[i].count(i+offset)>0)offset++;
        if(i+offset>h || ops[i].lower_bound(i+offset)==ops[i].end()){
            op[i]=h;
        }else{
            op[i]=*(ops[i].lower_bound(i+offset))-1;
        }
    }
    std::sort(op+1,op+w+1);
    printf("%d",op[1]);
    return 0;
}
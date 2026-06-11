#include<cstdio>

int min(int a,int b){ return a>b?b:a; }

int answer[300005];

int main(){
    long long n,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    if(a>n || b>n || a+b>n+1){ 
        printf("-1\n");
        return 0;
    }
    int tag = 0;
    if(a<b){
        tag = a;
        a = b;
        b = tag;
        tag = 1;
    }
    long long left = n-a;
    if(a*(b-1)<left) printf("-1\n");
    else{
        int need = left;
        int size = 0; int index = 0;
        for(int i = 1; i <= a; i++){
            int give = min(b-1,need);
            need -= give;
            int next = size+give+1;
            for(int j = 0; j < give; j++){
                answer[next--] = ++index;
            }
            answer[size+1] = ++index;
            size += give+1;
        }
        for(int i = 1; i <= size; i++){
            if(tag) printf("%d ",(int)n-answer[i]+1);
            else printf("%d ",answer[i]);
        }
        printf("\n");
    }
    return 0;
}


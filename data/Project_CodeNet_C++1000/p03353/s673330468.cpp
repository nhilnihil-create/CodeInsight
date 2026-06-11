#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
#define N 90005

struct SamNode{
    int l , sc;
    SamNode *son[26] , *f;
}sam[N<<1] , *root , *last , *b[N<<1];

int cnt , num[N] , n , k;
char s[N];
void add(int x)
{
    SamNode *p = &sam[++cnt] , *jp = last;
    p->l = jp->l+1;
    last = p;
    for(; jp&&!jp->son[x] ; jp=jp->f) jp->son[x] = p;
    if(!jp) p->f = root;
    else{
        if(jp->l+1 == jp->son[x]->l) p->f = jp->son[x];
        else{
            SamNode *r = &sam[++cnt] , *q = jp->son[x];
            *r = *q; r->l = jp->l+1;
            p->f = q->f = r;
            for( ; jp&&jp->son[x]==q ; jp=jp->f) jp->son[x] = r;
        }
    }
}

void build()
{
    int len = strlen(s);
    for(int i=0 ; i<len ; i++) add(s[i]-'a');
    for(int i=0 ; i<=cnt ; i++) num[sam[i].l]++;
    for(int i=1 ; i<=len ; i++) num[i]+=num[i-1];
    for(int i=0 ; i<=cnt ; i++) b[--num[sam[i].l]] = &sam[i];

    for(int i=cnt ; i>=1 ; i--){
        b[i]->sc=1;
        for(int j=0 ; j<26 ; j++){
            if(b[i]->son[j])
                b[i]->sc+=b[i]->son[j]->sc;
        }
    }
}

void solve()
{
   // scanf("%d" , &n);
    char tmp[N];
    int val , t;//t表示tmp中的位数
   
        scanf("%d" , &k);
        SamNode *cur = root;
        val = 0 , t=0;
        while(val<k){
            for(int i=0 ; i<26 ; i++){
                if(cur->son[i]){
                    if(val+cur->son[i]->sc<k) val+=cur->son[i]->sc;
                    else{
                        val++;
                        tmp[t++] = i+'a';
                        cur = cur->son[i];
                        break;
                    }
                }
            }
        }
        tmp[t]='\0';
        printf("%s\n" , tmp);
    
}

int main()
{
  //  freopen("a.in" , "r" , stdin);
    scanf("%s" , s);
    root = last = &sam[cnt=0];
    build();
    solve();
    return 0;
}
#include <set>  
#include <map>  
#include <math.h>  
#include <vector>  
#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
const double eps = 1e-8;  
using namespace std;  
   
set<int> x;  
set<int> y;  
set<int>::iterator it;  
   
void doit(int a,int now)  
{  
    if(now==0) return;  
    if(a==1){  
        set<int> y_;  
        y_.clear();  
        for(it = y.begin();it!=y.end();it++){  
            y_.insert(*it-now);  
            y_.insert(*it+now);  
        }  
        y.clear();  
        for(it = y_.begin();it!=y_.end();it++){  
            y.insert(*it);  
            y.insert(*it);  
        }  
    }else{  
        set<int> x_;  
        x_.clear();  
        for(it = x.begin();it!=x.end();it++){  
            x_.insert(*it-now);  
            x_.insert(*it+now);  
        }  
        x.clear();  
        for(it = x_.begin();it!=x_.end();it++){  
            x.insert(*it);  
            x.insert(*it);  
        }  
    }  
}  
   
int main()  
{  
    string s;  
    cin>>s;  
    int xx,yy;  
    scanf("%d%d",&xx,&yy);  
    int now=0;  
    int i;  
    for(i=0;i<s.length();i++){  
        if(s[i]=='F'){  
            now++;  
        }else{  
            break;  
        }  
    }  
    x.insert(now+10000);  
    y.insert(10000);  
    int a=1;  
    now=0;  
    for(i++;i<s.length();i++){  
        if(s[i]=='F'){  
            now++;  
        }else{  
            doit(a,now);  
            a^=1;  
            now=0;  
        }  
    }  
    doit(a,now);  
    if(x.find(xx+10000)!=x.end()&&y.find(yy+10000)!=y.end()){  
        printf("Yes\n");  
    }else  
        printf("No\n");  
   
   
}  
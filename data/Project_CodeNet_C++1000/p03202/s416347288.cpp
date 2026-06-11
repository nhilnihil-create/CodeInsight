#include<bits/stdc++.h>
#define M 1000000000
using std::stack;
using std::pair;
using std::vector;
stack<pair<int,int>> Q;
int n;
int a[200020];
vector<int> V;
long long pow(int a,int pw){
    if(pw==0) return 1;
    long long ans=pow(a,pw/2);
    if(ans==-1) return -1;
    ans=ans*ans;
    if(ans>=M) return -1;
    if(pw%2) ans*=a;
    if(ans>=M) return -1;
    return ans;
}
void reallocate(int no, int dim){
    pair<int,int> temp = Q.top(); Q.pop();
    pair<int,int> temptemp=Q.top();
    int mm = std::max(temptemp.first,no);
    if(temptemp.first<no && pow(dim,temp.first-mm)!=-1){
        Q.push({mm,1+(temp.second-1)/pow(dim,temp.first-mm)});
    }
    else if(temptemp.first>=no && pow(dim,temp.first-mm)!=-1){
        Q.pop();
        temptemp.second += (temp.second-1)/pow(dim,temp.first-mm);
        Q.push(temptemp);
    }
}
void input(int no,int dim){
    while(!Q.empty() && Q.top().first>no){
        reallocate(no,dim);
    }
    if(!Q.empty() && Q.top().first==no){
        pair<int,int> temp = Q.top(); Q.pop();
        ++temp.second;
        Q.push(temp);
    }
    else{
        Q.push({no,1});
    }
}
/*class comp{
public:
    bool operator()(const int& dim,const int& x){
        
        while(!Q.empty()) Q.pop();
        Q.push({1,1});
        if(a[0]>1) Q.push({a[0],1});
        for(int i=1;i<n;i++) input(a[i],dim);
        input(1,dim);
        if(Q.top().second>dim){
            return true;
            puts("T");
        }
        else return false;
    }
} CMP;*/
bool CMP(const int& dim,const int& x){
    //printf("%d %d\n",dim,x);
    while(!Q.empty()) Q.pop();
    Q.push({1,1});
    if(a[0]>1) Q.push({a[0],1});
    for(int i=1;i<n;i++) input(a[i],dim);
    input(1,dim);
    //printf("%d %d\n",Q.top().first,Q.top().second);
    if(Q.top().second>dim+1){
        //puts("T");
        return true;
    }
    else return false;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {V.push_back(i);}
    std::cout << *std::lower_bound(V.begin(),V.end(),1,CMP);
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
        Node(int _id, int _x):id(_id),x(_x){}
        int id;
        int x;
        bool operator<(const Node &node) const{
            return x<node.x;
        }
};

long long int walk(int p, const int n, const vector<Node> l, const vector<Node> r, vector<int> color){
    int pl = n-1;
    int pr = 0;
    long long int td = 0;
    for(int i=0;i<n;++i){
        while(pl>=0 && color[l[pl].id]==1){
            --pl;
        }
        while(pr<n && color[r[pr].id]==1){
            ++pr;
        }
        int ld = 0;
        int rd = 0;
        if(pl>=0){
            int x = l[pl].x;
            if(x>=p){
               ld = x-p; 
            }
        }
        if(pr<n){
            int x = r[pr].x;
            if(p>=x)
                rd = p-x;
        }
        if(pl>=0 && ld>=rd){
            p += ld;
            td += ld;
            color[l[pl].id] = 1;
            --pl;
        }
        else if(pr<n){
            p -= rd;
            td += rd;
            color[r[pr].id] = 1;
            ++pr;
        }
        //cout<<p<<" "<<td<<endl;
    }
    td+=abs(p);
    return td;
}
int main(){
    vector<Node> l;
    vector<Node> r;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        l.push_back(Node(i,x));
        r.push_back(Node(i,y));
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    vector<int> color(n);
    
    
    int p = 0;
    if(l[n-1].x>0){
        p = l[n-1].x;
        color[l[n-1].id] = 1;
    }
    long long int td1 = walk(p,n,l,r,color) + p;
    //fill(color.begin(),color.end(),0);
    for(int i=0;i<color.size();++i)
        color[i] = 0;
    p = 0;
    if(r[0].x<0){
        p = r[0].x;
        color[r[0].id] = 1;
    }
    long long int td2 = walk(p,n,l,r,color) - p;
    long long int td = td1>td2?td1:td2;
    cout<<td<<"\n";
}

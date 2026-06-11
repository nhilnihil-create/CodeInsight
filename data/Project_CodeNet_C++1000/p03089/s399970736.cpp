
#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>

typedef long long ll;

using namespace std;

struct B {
    int old;
    int num;
    int nw=0;
};

int main() {
    
    int N;
    cin>>N;
    vector<B> vb(N);
    list<B> ls;
    int numb=N;
    for(int i=0;i<N;++i){
        cin>>vb[i].num;
        vb[i].old=numb;
        --numb;
    }
    
    
    
    int count=1;
    
    
    
    for(int i=1;i<=N;++i){
        
        for(int j=N-1;j>=0;--j){
            if(vb[j].num>i)continue;
            //cout<<"judge1"<<endl;
            if(vb[j].nw!=0)continue;
            //cout<<"judge2"<<endl;
            bool flag=true;
            for(list<B>::iterator itr=ls.begin();itr!=next(ls.begin(),vb[j].num-1);++itr){
                if(itr->old<vb[j].old){
                    flag=false;
                    break;
                }
            }
            if(flag){
                vb[j].nw=count;
                ls.insert(next(ls.begin(),vb[j].num-1),vb[j]);
                
                ++count;
                
               // cout<<vb[j].num<<endl;
                break;
            }
            
            //cout<<"--------->>>"<<endl;
            /*
            for(list<B>::iterator itr=ls.begin();itr!=ls.end();++itr){
                cout<<itr->num<<" ";
                
            }
            cout<<endl;
            */
            
            
        }
    }
   // cout<<"============="<<endl;
    /*
    for(int i=0;i<N;++i){
        cout<<vb[i].old<<" ";
        cout<<vb[i].num<<" ";
        cout<<vb[i].nw<<" ";
        
    }
    cout<<endl;
    
    cout<<"============="<<endl;
    */
    sort(vb.begin(),vb.end(),[](B a,B b){return  a.nw<b.nw;});
    
    /*
    cout<<"============="<<endl;
    
    for(int i=0;i<N;++i){
        cout<<vb[i].old<<" ";
        cout<<vb[i].num<<" ";
        cout<<vb[i].nw<<" ";
        
    }
    cout<<endl;
    
    cout<<"============="<<endl;
     
     */
     
    if(vb[0].nw==0){
        cout<<-1<<endl;
    }else{
        for(int i=0;i<N;++i){
            cout<<vb[i].num<<endl;
        }
    }
    
    
}


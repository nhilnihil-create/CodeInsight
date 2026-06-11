    #include<iostream>
    using namespace std;
    int main(){
        unsigned long long int first=2;
        unsigned long long int second=1;
        unsigned long long int n;
        cin>>n;
        if(n==0)
        {
            cout<<first;
        }
        else
        if(n==1)
        {
            cout<<second;
        }
        else
        {
            n--;
            while(n>0)
            {
                unsigned long long int sum=first+second;
                first=second;
                second=sum;
                n--;
            }
            cout<<second;
        }
        
    }
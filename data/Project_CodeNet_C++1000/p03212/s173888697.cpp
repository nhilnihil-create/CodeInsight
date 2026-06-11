#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

template<class T>
void ALLOUT1(vector<T> V)
{
    ll N = V.size();
    for(ll i=0;i<N;i++)
    {
        cout << V[i];
        if(i!=N-1) cout << ' ';
    }
    cout << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

vector<ll> Change_to_vector(ll N)
{
    vector<ll> ret;
    while(N>0)
    {
        ret.push_back(N-(N/10)*10);
        N = (N/10);
    }
    reverse(ALL(ret));
    return ret;
}

void pattarn(vector<ll> N_vector, ll depth, ll& pattarn_counter, vector<ll> used_753, vector<ll> pattarn_now, bool suspicious)
{
    if(depth == N_vector.size())
    {
        if(used_753[0]!=0 && used_753[1]!=0 && used_753[2]!=0) pattarn_counter++;
        return;
    }
    else
    {
        if(suspicious)
        {
            if(N_vector[depth]>=7)
            {
                vector<ll> pattarn_now_copy = pattarn_now;
                pattarn_now_copy.push_back(7);
                vector<ll> used_753_copy = used_753;
                used_753_copy[0]++;
                if(N_vector[depth]!=7) suspicious = false;
                pattarn(N_vector,depth+1,pattarn_counter,used_753_copy,pattarn_now_copy,suspicious);
            }
            if(N_vector[depth]>=5)
            {
                vector<ll> pattarn_now_copy = pattarn_now;
                pattarn_now_copy.push_back(5);
                vector<ll> used_753_copy = used_753;
                used_753_copy[1]++;
                if(N_vector[depth]!=5) suspicious = false;
                pattarn(N_vector,depth+1,pattarn_counter,used_753_copy,pattarn_now_copy,suspicious);    
            }
            if(N_vector[depth]>=3)
            {
                vector<ll> pattarn_now_copy = pattarn_now;
                pattarn_now_copy.push_back(3);
                vector<ll> used_753_copy = used_753;
                used_753_copy[2]++;
                if(N_vector[depth]!=3) suspicious = false;
                pattarn(N_vector,depth+1,pattarn_counter,used_753_copy,pattarn_now_copy,suspicious);
            }
        }
        else
        {
            {
                vector<ll> pattarn_now_copy = pattarn_now;
                pattarn_now_copy.push_back(7);
                vector<ll> used_753_copy = used_753;
                used_753_copy[0]++;
                if(N_vector[depth]!=7) suspicious = false;
                pattarn(N_vector,depth+1,pattarn_counter,used_753_copy,pattarn_now_copy,suspicious);
            }
            {
                vector<ll> pattarn_now_copy = pattarn_now;
                pattarn_now_copy.push_back(5);
                vector<ll> used_753_copy = used_753;
                used_753_copy[1]++;
                if(N_vector[depth]!=5) suspicious = false;
                pattarn(N_vector,depth+1,pattarn_counter,used_753_copy,pattarn_now_copy,suspicious);
            }
            {
                vector<ll> pattarn_now_copy = pattarn_now;
                pattarn_now_copy.push_back(3);
                vector<ll> used_753_copy = used_753;
                used_753_copy[2]++;
                if(N_vector[depth]!=3) suspicious = false;
                pattarn(N_vector,depth+1,pattarn_counter,used_753_copy,pattarn_now_copy,suspicious);
            }
        }
    }
}

ll njou_3(ll N)
{
    if(N==0) return 1;
    else if(N==1) return 3;
    else
    {
        if(N%2==0) return njou_3(N/2) * njou_3(N/2);
        else return njou_3((N+1)/2) * njou_3((N-1)/2);
    }
}

void Ans(vector<ll> N_vector, ll& pattarn_counter)
{
    ll suspicious = true;
    vector<ll> pattarn_now = {0};
    for(ll i=0;i<N_vector.size();i++)
    {
        pattarn(N_vector,i,pattarn_counter,{0,0,0},pattarn_now,suspicious);
        pattarn_now.push_back(0);
        suspicious = false;
    }
}

int main()
{
    ll N;
    cin >> N;

    ll pattarn_counter = 0;
    Ans(Change_to_vector(N),pattarn_counter);

    OUT0(pattarn_counter);

    return 0;
}
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

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

class Node
{
    public:
    ll counter = 1e9;
    ll x;
    ll y;
    bool color = false; // 白:true 黒:false
    bool seen = false;
};

void ALLIN_GRAPH(ll H, ll W, vector<vector<Node>>& Graph, ll& black_number)
{
    black_number = 0;
    for(ll i=1;i<H+1;i++)
    {
        string s;
        cin >> s;
        for(ll j=1;j<W+1;j++)
        {
            if(s[j-1]=='.') Graph[i][j].color = true;
            else
            {
                black_number++;
            }
            Graph[i][j].x = j;
            Graph[i][j].y = i;
        }
    }
}

void BFS(vector<vector<Node>>& Graph)
{
    queue<Node> bfs;
    Graph[1][1].counter = 0;
    bfs.push(Graph[1][1]);

    while(!bfs.empty())
    {
        Node front_copy = bfs.front();
        bfs.pop();
        if(Graph[front_copy.y-1][front_copy.x].color)
        {
            if(!Graph[front_copy.y-1][front_copy.x].seen)
            {
                Graph[front_copy.y-1][front_copy.x].seen = true;
                Graph[front_copy.y-1][front_copy.x].counter = front_copy.counter+1;
                bfs.push(Graph[front_copy.y-1][front_copy.x]);
            }
        } 
        if(Graph[front_copy.y+1][front_copy.x].color)
        {
            if(!Graph[front_copy.y+1][front_copy.x].seen)
            {
                Graph[front_copy.y+1][front_copy.x].seen = true;
                Graph[front_copy.y+1][front_copy.x].counter = front_copy.counter+1;
                bfs.push(Graph[front_copy.y+1][front_copy.x]);
            }
        } 
        if(Graph[front_copy.y][front_copy.x+1].color)
        {
            if(!Graph[front_copy.y][front_copy.x+1].seen)
            {
                Graph[front_copy.y][front_copy.x+1].seen = true;
                Graph[front_copy.y][front_copy.x+1].counter = front_copy.counter+1;
                bfs.push(Graph[front_copy.y][front_copy.x+1]);
            }
        } 
        if(Graph[front_copy.y][front_copy.x-1].color)
        {
            if(!Graph[front_copy.y][front_copy.x-1].seen)
            {
                Graph[front_copy.y][front_copy.x-1].seen = true;
                Graph[front_copy.y][front_copy.x-1].counter = front_copy.counter+1;
                bfs.push(Graph[front_copy.y][front_copy.x-1]);
            }
        }
    }
}

int main()
{
    ll H,W;
    cin >> H >> W;

    vector<vector<Node>> Graph(H+2,vector<Node>(W+2));
    ll black_number;
    ALLIN_GRAPH(H,W,Graph,black_number);

    BFS(Graph);

    ll ans = (H*W - (Graph[H][W].counter + 1) - black_number); 

    if(Graph[H][W].counter == 1e9)
    {
        OUT0(-1);
    } 
    else
    {
        OUT0(ans);
    }

    return 0;
}
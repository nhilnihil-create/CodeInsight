#include<iostream>
#include<vector>

int moveS(int poz, int Q, std::vector<std::pair<char, char>>squareMoves, std::string s)
{
    int len = s.size();
    if(poz < 0)
    {
        return -1;
    }
    if(poz >= len)
    {
        return 1;
    }
    for(int i = 0; i < Q; i++)
    {
        if(squareMoves[i].first != s[poz]) continue;
        if(squareMoves[i].second == 'L')
        {
            poz--;
        }
        else
        {
            poz++;
        }
        if(poz >= len)
        {
            return 1;
        }
        if(poz < 0)
        {
            return -1;
        }
    }

    return 0;
}


int main()
{
    int N, Q;

    std:: cin >> N >> Q;

    std::string s;
    std::cin >> s;

    std::vector<int> count(s.size()+2, 1);
    count[0] = count[s.size()+1] = 0;

    std::vector<std::pair<char, char>>squareMoves;
    for(int i = 0; i < Q; ++i)
    {
        char square, move;
        std:: cin >> square >> move;

        squareMoves.push_back(std::make_pair(square, move));
    }


    int st, dr;
    st = -1;
    dr = N + 1;

    while(st < dr-1)
    {
        int mij = (st+dr)/2;
        //std::cout << moveS(mij, Q, squareMoves, s);
        if(moveS(mij, Q, squareMoves, s) == -1)
        {
            st = mij;
        }
        else
        {
            dr = mij;
        }
    }
    //std::cout << dr;
    int sol1 = dr;

    st = -1;
    dr = N + 1;
    while(st < dr-1)
    {
        int mij = (st+dr)/2;
        if(moveS(mij, Q, squareMoves, s) == 0 || moveS(mij, Q, squareMoves, s) == -1)
        {
            st = mij;
        }
        else
        {
            dr = mij;
        }
    }
    //std::cout << dr;
    int sol2 = dr;

    std::cout << sol2 - sol1;
    return 0; 
}